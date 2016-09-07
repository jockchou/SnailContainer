namespace SnailContainer\Exception;

use RuntimeException;
use Psr\Container\Exception\NotFoundExceptionInterface;

/**
 * No entry was found in the container.
 */
class ContainerNotFoundException extends \RuntimeException implements NotFoundExceptionInterface
{

}